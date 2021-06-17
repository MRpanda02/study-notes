# 用栈解决迷宫问题

maze = [[1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
        [1, 0, 0, 1, 0, 0, 0, 1, 0, 1],
        [1, 0, 0, 1, 0, 0, 0, 1, 0, 1],
        [1, 0, 0, 0, 0, 1, 1, 0, 0, 1],
        [1, 0, 1, 1, 1, 0, 0, 0, 0, 1],
        [1, 0, 1, 0, 0, 0, 1, 0, 0, 1],
        [1, 0, 0, 1, 1, 0, 1, 1, 0, 1],
        [1, 0, 0, 1, 1, 0, 1, 1, 0 ,1],
        [1, 1, 0, 0, 0, 0, 0, 0, 0, 1],
        [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]]

dirs = [
    lambda x, y:(x+1, y),
    lambda x, y:(x-1, y),
    lambda x, y:(x, y+1),
    lambda x, y:(x, y-1)
]
def MazePath(x1, y1, x2, y2):
    stack = []
    stack.append((x1, y1))
    while(len(stack)>0):
        CurNode = stack[-1]
        if CurNode[0] == x2 and CurNode[1] == y2:
            for mazepath in stack:
                print(mazepath)
            return True
        for dir in dirs:
            NextNode = dir(CurNode[0],CurNode[1])
            if maze[NextNode[0]][NextNode[1]] == 0:
                stack.append(NextNode)
                maze[NextNode[0]][NextNode[1]] = 2
                break
        else:
            stack.pop()
    else:
        print("没有路")
        return False

if __name__ == '__main__':
    MazePath(1, 1, 8, 8)