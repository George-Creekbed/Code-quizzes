def print_formatted(number):
    width = len(format(number, 'b'))
    for i in range(1, number+1):
        print('{0:{w}{d}} {0:{w}{o}} {0:{w}{x}} {0:{w}{b}}'.\
            format(i, w = width, d='d', o='o', x='X', b='b')
        )

if __name__ == '__main__':
    n = int(input())
    print_formatted(n)
