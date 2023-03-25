int n = 10, m = 10;
int endx = 10, endy = 10;
bool is_find[1003][1003] = {false};

void wip(int x, int y, int dis, int cur)
{
    if (x < 0 || y < 0 || x >= n || y >= m) return;
    if (is_find[x][y]) return;
    
    // ending condition
    if(x = endx && y == endy) return;

    is_find[x][y] = true;

    wip(x + 1, y, dis, cur + 1);
    wip(x, y + 1, dis, cur + 1);
    wip(x - 1, y, dis, cur + 1);
    wip(x, y - 1, dis, cur + 1);
}