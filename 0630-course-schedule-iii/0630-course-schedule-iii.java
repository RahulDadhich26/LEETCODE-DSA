class Solution {
    public int scheduleCourse(int[][] courses) {
         Arrays.sort(courses, (a, b) -> a[1] - b[1]);

        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a); // max heap
        int time = 0;

        for (int[] course : courses) {
            time += course[0]; // Add duration
            pq.add(course[0]); // Add to heap

            if (time > course[1]) {
                time -= pq.poll(); // Remove the longest duration course
            }
        }

        return pq.size();
    }
}