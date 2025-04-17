import calculator
import io_handler

def main():
    a, b = io_handler.get_input()
    operation = input("请选择操作 (+, -, *, /): ")

    if operation == '+':
        result = calculator.add(a, b)
    elif operation == '-':
        result = calculator.subtract(a, b)
    elif operation == '*':
        result = calculator.multiply(a, b)
    elif operation == '/':
        result = calculator.divide(a, b)
    else:
        result = "无效操作"

    io_handler.display_result(result)

if __name__ == "__main__":
    main()