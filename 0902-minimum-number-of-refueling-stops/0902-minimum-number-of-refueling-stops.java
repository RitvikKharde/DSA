class Solution {
    public int minRefuelStops(int target, int startFuel, int[][] stations) {
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        int currentFuel = startFuel;
        int stops = 0;
        int prevPosition = 0;
        
        for (int[] station : stations) {
            int position = station[0];
            int fuel = station[1];
            int distance = position - prevPosition;
            while (currentFuel < distance && !maxHeap.isEmpty()) {
                currentFuel += maxHeap.poll();
                stops++;
            }
            if (currentFuel < distance) {
                return -1;
            }
            currentFuel -= distance;
            maxHeap.offer(fuel);
            prevPosition = position;
        }
        
        // After processing all stations, check remaining distance to target
        int remainingDistance = target - prevPosition;
        while (currentFuel < remainingDistance && !maxHeap.isEmpty()) {
            currentFuel += maxHeap.poll();
            stops++;
        }
        if (currentFuel < remainingDistance) {
            return -1;
        }
        
        return stops;
    }
}