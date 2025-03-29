import os
import time
import json
import requests
import git
from datetime import datetime
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.chrome.options import Options

# 🔹 Replace with your actual credentials
LEETCODE_USERNAME = "your_leetcode_username"
LEETCODE_PASSWORD = "your_leetcode_password"

# 🔹 Set your GitHub Repository Path (where solutions will be stored)
GITHUB_REPO_PATH = "/absolute/path/to/LEETCODE"

# 🔹 Chrome WebDriver Setup
chrome_options = Options()
chrome_options.add_argument("--headless")  # Run in headless mode
chrome_service = Service("/path/to/chromedriver")  # Replace with actual ChromeDriver path
driver = webdriver.Chrome(service=chrome_service, options=chrome_options)

# 🔹 Log in to LeetCode
driver.get("https://leetcode.com/accounts/login/")
time.sleep(3)

username_input = driver.find_element(By.NAME, "login")
password_input = driver.find_element(By.NAME, "password")

username_input.send_keys(LEETCODE_USERNAME)
password_input.send_keys(LEETCODE_PASSWORD)
password_input.send_keys(Keys.RETURN)

time.sleep(5)  # Wait for login to complete

# 🔹 Get today's date
today_date = datetime.today().strftime('%Y-%m-%d')

# 🔹 Fetch only today's submissions
driver.get("https://leetcode.com/api/submissions/")
time.sleep(5)

data = driver.find_element(By.TAG_NAME, "pre").text
submissions = json.loads(data)

# 🔹 Create a directory for new solutions
solutions_path = os.path.join(GITHUB_REPO_PATH, "LeetCode-Solutions")
os.makedirs(solutions_path, exist_ok=True)

# 🔹 Process only today's submissions
new_solutions = []
for submission in submissions.get("submissions_dump", []):
    submission_date = submission["timestamp"]
    submission_date = datetime.utcfromtimestamp(submission_date).strftime('%Y-%m-%d')

    if submission_date == today_date:
        title = submission["title"]
        code = submission["code"]
        lang = submission["lang"]

        # Generate filename
        file_extension = {"python": "py", "cpp": "cpp", "java": "java"}.get(lang, "txt")
        filename = f"{title.replace(' ', '_')}.{file_extension}"
        file_path = os.path.join(solutions_path, filename)

        # Save the new solution
        with open(file_path, "w") as f:
            f.write(code)

        new_solutions.append(filename)

# 🔹 Close the browser
driver.quit()

# 🔹 If no new solutions, exit
if not new_solutions:
    print("✅ No new solutions today. Exiting.")
    exit()

# 🔹 Push to GitHub
repo = git.Repo(GITHUB_REPO_PATH)
repo.git.add(A=True)
repo.index.commit(f"Auto-synced {len(new_solutions)} new LeetCode solutions on {today_date}")
origin = repo.remote(name="origin")
origin.push()

print(f"✅ Successfully synced {len(new_solutions)} new solutions to GitHub!")
