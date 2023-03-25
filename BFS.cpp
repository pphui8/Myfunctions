int n = 10, m = 10;
int endx = 10, endy = 10;
bool is_find[1003][1003] = {false};

int mov[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
void DFS(int x, int y, int cur)
{
    // ending condition
    if (x = endx && y == endy) return;

    for (int i = 0; i < 4; i++) {
        int xx = x + mov[i][0];
        int yy = y + mov[i][1];
        if (xx >= n || xx < 0 || yy >= m || yy < 0 || is_find[xx][yy]) continue;
        cur++;
        is_find[xx][yy] = 1;
        DFS(xx, yy, cur);
        is_find[xx][yy] = 0;
        cur--;
    }
}