// class Solution {
//     public int minRefuelStops(int target, int startFuel, int[][] stations) {
//         PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
//         int currentFuel = startFuel;
//         int stops = 0;
//         int prevPosition = 0;
        
//         for (int[] station : stations) {
//             int position = station[0];
//             int fuel = station[1];
//             int distance = position - prevPosition;
//             while (currentFuel < distance && !maxHeap.isEmpty()) {
//                 currentFuel += maxHeap.poll();
//                 stops++;
//             }
//             if (currentFuel < distance) {
//                 return -1;
//             }
//             currentFuel -= distance;
//             maxHeap.offer(fuel);
//             prevPosition = position;
//         }
        
//         // After processing all stations, check remaining distance to target
//         int remainingDistance = target - prevPosition;
//         while (currentFuel < remainingDistance && !maxHeap.isEmpty()) {
//             currentFuel += maxHeap.poll();
//             stops++;
//         }
//         if (currentFuel < remainingDistance) {
//             return -1;
//         }
        
//         return stops;
//     }
// }



import java.util.PriorityQueue;
import java.util.Collections;

class Solution {
    public int minRefuelStops(int target, int startFuel, int[][] stations) {
        // We use a max-heap to keep track of the fuel available at stations we've passed but haven't used yet.
        // The heap will always give us the station with the most fuel when we need to refuel.
        PriorityQueue<Integer> availableFuel = new PriorityQueue<>(Collections.reverseOrder());
        
        int currentFuel = startFuel; // The fuel we currently have in the tank.
        int stops = 0; // Number of refueling stops made so far.
        int previousPosition = 0; // The last position we were at (start at 0).
        
        // Go through each gas station along the route.
        for (int[] station : stations) {
            int stationPosition = station[0];
            int stationFuel = station[1];
            
            // The distance to the next station from where we are.
            int distanceToNextStation = stationPosition - previousPosition;
            
            // If we don't have enough fuel to reach the next station, refuel from the best available stations we've passed.
            while (currentFuel < distanceToNextStation && !availableFuel.isEmpty()) {
                currentFuel += availableFuel.poll(); // Refuel from the station with the most fuel.
                stops++; // Increment the stop count.
            }
            
            // If we still don't have enough fuel after using all available stations, we can't reach the next station.
            if (currentFuel < distanceToNextStation) {
                return -1;
            }
            
            // Now that we've reached the station, subtract the fuel used to get here.
            currentFuel -= distanceToNextStation;
            
            // Add this station's fuel to our list of available stations for future refueling.
            availableFuel.offer(stationFuel);
            
            // Update our position to this station.
            previousPosition = stationPosition;
        }
        
        // After passing all stations, we still need to reach the target.
        int distanceToTarget = target - previousPosition;
        
        // If we don't have enough fuel to reach the target, refuel from the remaining available stations.
        while (currentFuel < distanceToTarget && !availableFuel.isEmpty()) {
            currentFuel += availableFuel.poll();
            stops++;
        }
        
        // If we still can't reach the target, return -1.
        if (currentFuel < distanceToTarget) {
            return -1;
        }
        
        // Return the total number of refueling stops made.
        return stops;
    }
}