# match brace to use stack

from stack_demo import Stack

def brace_match(li):
    match = {'}': '{', ']': '[', ')': '('}
    stack = Stack()
    for ch in li:
        if ch in {'{', '(', '['}:
            stack.push(ch)
        else:
            if stack.is_empty():
                return False
            elif stack.get_pop() == match[ch]:
                stack.pop()
            else:
                return False
    if stack.is_empty():
        return True
    else:
        return False


if __name__ == '__main__':
    print(brace_match('[{()(){}]'))