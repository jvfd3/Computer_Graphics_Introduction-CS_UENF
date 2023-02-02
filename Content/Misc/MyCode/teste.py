'''teste'''

from tkinter import *


def ytb_video():
    '''test'''

    size = {
        'w': 500,
        'h': 400
    }
    tk = Tk()
    canvas = Canvas(tk, width=size['w'], height=size['h'])
    tk.title('Drawing')
    canvas.pack()

    canvas.create_line(0, 0, 500, 400)
    canvas.create_rectangle(100, 100, 250, 250, fill='blue')
    canvas.create_oval(10, 10, 50, 50, fill='green')
    canvas.create_polygon(400, 10, 300, 300, 500, 300, fill='purple')

    canvas.mainloop()


def regular_polygon():
    '''test'''
    def get_number_of_points(auto=True):
        message = 'Type the number of points to be calculated: '
        number_of_points = 5 if auto else int(input(message))
        # print('Number of points chosen ', 'automatically' if auto else 'manually',' : ', number_of_points)
        return number_of_points

    # print(get_number_of_points(False))
    # print(min(123, 321, 2))


def main():
    '''test'''
    # ytb_video()
    regular_polygon()


main()
