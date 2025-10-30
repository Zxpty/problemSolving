# genera_array_linea.py
with open("resultado.txt") as f:
    lines = f.readlines()

# eliminamos saltos de línea y aseguramos el orden
nums = [line.strip() for line in lines if line.strip()]

# escribimos en un nuevo TXT todo en una sola línea como array C++
with open("array_cpp.txt", "w") as fout:
    fout.write("long long a[] = {")
    fout.write(", ".join(nums))
    fout.write("};\n")

