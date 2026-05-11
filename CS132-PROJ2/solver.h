#include "stack.h"
class maze
{
public:

    maze(int, int);
	int xpos, ypos;
	char coordinates[12][12]{ 0 };
	bool visitedCells[12][12]{ 0 };
	bool free = false;
	bool wall = false;
	bool border = false;

	bool checkCell(const int&, const int&);
	bool solveMaze(maze&, int&, int&);
};

maze::maze(int x, int y) 
{
    {
        xpos = x, ypos = y;
    }
}

struct Coord
{
	int x, y;
};

bool maze::checkCell(const int& x,const int& y)
{
	if (this->coordinates[x][y] == '#')
	{
		free = false;
		border = true;
        return true;
	}
	else if (this->coordinates[x][y] == '1')
	{
		free = false;
		wall = true;
        return true;
	}
	else if (this->coordinates[x][y] == '0')
	{
		return false;
	}
	else if (this->coordinates[x][y] == 'E')
	{
		free = true;
		wall = false;
		border = false;
		return false;
	}
	else
	{
		return false;
	}
}

bool solveMaze(maze& m, int startX, int startY) {
    Stack<Coord> s;

    // check if start is wall
    if (m.checkCell(startX, startY)) {
        cout << "Start position is trapped (Wall/Border)! Cannot solve.\n";
        return false;
    }

    // check if start is already the exit 'E'
    if (m.coordinates[startX][startY] == 'E') {
        cout << "Start is already the exit!\n";
        return true;
    }

    // push start
    s.push({ startX, startY });

    //while not free & not trapped
    while (!s.emptyS()) {

        // peek at the top
        Coord current = *s.top();
        int x = current.x;
        int y = current.y;

        // check up to see if exit
        if (m.coordinates[x][y] == 'E') {
            m.visitedCells[x][y] = true;
            cout << "\n";
            cout << "   ================================================\n";
            cout << "   ||MY MAZE MASTER MASTERED MY MAZE. MAZE MASTER||\n";
            cout << "   ================================================\n";
            cout << "\n";
            void drawSolution(const maze & m);
            return true;
        }

        // check if trapped
        bool isWall = m.checkCell(x, y);
        bool isVisited = m.visitedCells[x][y];

        // while the top is trapped (wall or visited) and stack isn't empty
        while ((isWall || isVisited) && !s.emptyS()) {
            s.pop();

            if (!s.emptyS()) {
                current = *s.top();
                x = current.x;
                y = current.y;

                isWall = m.checkCell(x, y);
                isVisited = m.visitedCells[x][y];
            }
        }

        // if stack became empty during backtracking, no path exists
        if (s.emptyS()) 
        {
            void displaySolution(const maze m);
            return false;
        }

        // valid cell on top now
        s.pop();
           
        //mark visited
        m.visitedCells[x][y] = true;
        m.coordinates[x][y] = '*'; 

        // put cell back onto stack
        s.push({ x, y });

        int dx[] = { 0, 0, -1, 1 };
        int dy[] = { -1, 1, 0, 0 };

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= 12 || ny < 0 || ny >= 12) 
                continue;

            // check neighbor
            bool neighborIsWall = m.checkCell(nx, ny);
            bool neighborIsVisited = m.visitedCells[nx][ny];

            if (!neighborIsWall && !neighborIsVisited) {
                s.push({ nx, ny });
            }
        }
    }
    return false;
}

#pragma once
