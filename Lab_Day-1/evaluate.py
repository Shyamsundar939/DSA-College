# Evaluate post-fix expression. 

postfix = input("Enter postfix expression : ")
symbols = postfix.split()
stack = []
for s in symbols:
    try:
        stack.append(float(s))
    except ValueError:
        first_val = stack.pop()
        second_val = stack.pop()

        if s == "+":
            stack.append(second_val + first_val)
        elif s == "-":
            stack.append(second_val - first_val)
        elif s == "*":
            stack.append(second_val * first_val)
        elif s == "/":
            stack.append(second_val / first_val)
        elif s == "^":
            stack.append(second_val ** first_val)

print("The final result is  : ", stack[0])