import java.util.ArrayDeque;
import java.util.Scanner;

public class ccc18s3v2 {

    private static int M, N;
    private static char[][] map = new char[101][101];
    private static int[][] dp = new int[101][101];
    private static boolean[][] visited = new boolean[101][101];

    private enum Direction {
        UP(0, 1),
        DOWN(0, -1),
        LEFT(-1, 0),
        RIGHT(1, 0);

        public final int x;
        public final int y;

        Direction(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    private static class Point {
        public int x;
        public int y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    private static void expandCamera(Point p) {
        int x = p.x;
        int y = p.y;
        do {
            x--;
            if (map[x][y] == '.') {
                map[x][y] = 'X';
            } else if (map[x][y] == 'W') {
                break;
            }
        } while (x >= 0);
        x = p.x;
        y = p.y;
        do {
            x++;
            if (map[x][y] == '.') {
                map[x][y] = 'X';
            } else if (map[x][y] == 'W') {
                break;
            }
        } while (x < N);
        x = p.x;
        y = p.y;
        do {
            y--;
            if (map[x][y] == '.') {
                map[x][y] = 'X';
            } else if (map[x][y] == 'W') {
                break;
            }
        } while (y >= 0);
        x = p.x;
        y = p.y;
        do {
            y++;
            if (map[x][y] == '.') {
                map[x][y] = 'X';
            } else if (map[x][y] == 'W') {
                break;
            }
        } while (y < N);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] line = scanner.nextLine().trim().split(" ");
        N = Integer.parseInt(line[0]);
        M = Integer.parseInt(line[1]);

        Point start = null;
        for (int i = 0; i < N; i++) {
            char[] mapLine = scanner.nextLine().trim().toCharArray();
            for (int j = 0; j < M; j++) {
                map[i][j] = mapLine[j];
                if (mapLine[j] == 'S') {
                    start = new Point(i, j);
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] == 'C') {
                    expandCamera(new Point(i, j));
                }
            }
        }

        ArrayDeque<Point> deque = new ArrayDeque<>();
        dp[start.x][start.y] = 0;
        visited[start.x][start.y] = true;

        deque.addLast(start);
        while (!deque.isEmpty()) {
            Point curPoint = deque.removeFirst();
            for (Direction direction : Direction.values()) {
                Point testPoint = new Point(curPoint.x + direction.x, curPoint.y + direction.y);
                if (!visited[testPoint.x][testPoint.y]) {
                    switch (map[testPoint.x][testPoint.y]) {
                        case '.':
                            deque.addLast(testPoint);
                            dp[testPoint.x][testPoint.y] = dp[curPoint.x][curPoint.y] + 1;
                            visited[testPoint.x][testPoint.y] = true;
                            break;
                        case 'L':
                        case 'R':
                        case 'U':
                        case 'D':
                            deque.addLast(testPoint);
                            dp[testPoint.x][testPoint.y] = dp[curPoint.x][curPoint.y];
                            visited[testPoint.x][testPoint.y] = true;
                            break;
                    }
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] == '.') {
                    if (visited[i][j]) {
                        System.out.println(dp[i][j]);
                    } else {
                        System.out.println(-1);
                    }
                } else if (map[i][j] == 'X') {
                    System.out.println(-1);
                }
            }
        }
    }

}
