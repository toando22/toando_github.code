import tkinter as tk
from tkinter import filedialog

def sum_numbers():
    try:
        a = float(entry_a.get())
        b = float(entry_b.get())
        result_label.config(text="Kết quả: " + str(a + b))
    except ValueError:
        result_label.config(text="Vui lòng nhập số hợp lệ!")

def browse_file():
    file_path = filedialog.askopenfilename()
    file_path_entry.delete(0, tk.END)
    file_path_entry.insert(0, file_path)

def exit_program():
    window.destroy()

# Tạo một cửa sổ
window = tk.Tk()
window.title("Chương trình giải phép cộng")

# Tạo các label và textbox cho số a và số b
label_a = tk.Label(window, text="Nhập số a:")
label_a.grid(row=0, column=0)
entry_a = tk.Entry(window)
entry_a.grid(row=0, column=1)

label_b = tk.Label(window, text="Nhập số b:")
label_b.grid(row=1, column=0)
entry_b = tk.Entry(window)
entry_b.grid(row=1, column=1)

# Tạo một nút để tính tổng của hai số
sum_button = tk.Button(window, text="Tính tổng", command=sum_numbers)
sum_button.grid(row=2, column=0, columnspan=2, pady=5)

# Label để hiển thị kết quả
result_label = tk.Label(window, text="")
result_label.grid(row=3, column=0, columnspan=2)

# Tạo một textbox để nhập đường dẫn tới file
file_path_label = tk.Label(window, text="Chọn file:")
file_path_label.grid(row=4, column=0)

file_path_entry = tk.Entry(window, width=30)
file_path_entry.grid(row=4, column=1)

# Tạo một nút để duyệt file
browse_button = tk.Button(window, text="Duyệt", command=browse_file)
browse_button.grid(row=5, column=0, columnspan=2, pady=5)

# Tạo một nút để thoát
exit_button = tk.Button(window, text="Thoát", command=exit_program)
exit_button.grid(row=6, column=0, columnspan=2, pady=5)

# Vòng lặp main của ứng dụng
window.mainloop()
