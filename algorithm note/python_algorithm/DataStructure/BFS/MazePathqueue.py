# 用栈解决迷宫问题

maze = [[1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
        [1, 0, 0, 1, 0, 0, 0, 1, 0, 1],
        [1, 0, 0, 1, 0, 0, 0, 1, 0, 1],
        [1, 0, 0, 0, 0, 1, 1, 0, 0, 1],
        [1, 0, 1, 1, 1, 0, 0, 0, 0, 1],
        [1, 0, 1, 0, 0, 0, 1, 0, 0, 1],
        [1, 0, 0, 1, 1, 0, 1, 1, 0, 1],
        [1, 0, 0, 1, 1, 0, 1, 1, 0, 1],
        [1, 1, 0, 0, 0, 0, 0, 0, 0, 1],
        [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]]

dirs = [
    lambda x, y:(x+1, y),
    lambda x, y:(x-1, y),
    lambda x, y:(x, y+1),
    lambda x, y:(x, y-1)
]

def print_r(path):
    CurNode = path[-1]
    realpath = []

    while CurNode[2] != -1:
        realpath.append(CurNode[0:2])
        CurNode = path[CurNode[2]]

    realpath.append(CurNode[0:2])
    realpath.reverse()
    for p in realpath:
        print(p)

from collections import deque

def MazePathQueue(x1, y1, x2, y2):
    mazepath = deque()                           # 每次都会把mazepathpop到path路径用来记录下一条路和这个位置的关系
    path = []
    mazepath.append((x1, y1, -1))
    while(len(mazepath)>0):
        CurNode = mazepath.pop()
        path.append(CurNode)
        if CurNode[0] == x2 and CurNode[1] == y2:
            print_r(path)
            return True
        for dir in dirs:
            NextNode = dir(CurNode[0],CurNode[1])
            if maze[NextNode[0]][NextNode[1]] == 0:
                mazepath.append((NextNode[0], NextNode[1], len(path) - 1))          #下一次的放到mazepath里
                maze[NextNode[0]][NextNode[1]] = 2
    else:
        print("没有路")
        return False

if __name__ == '__main__':
    MazePathQueue(1, 1, 8, 8)