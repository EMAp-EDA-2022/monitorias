import capivara as cp

cf = cp.CapiFrame(10)

print(f"Max number of columns: {cf.max_columns}")
print(f"Number of columns: {cf.GetNumberColumns()}")

cf.NewColumn(5, "idade")
cf.NewColumn(5, "peso")

print(f"Number of columns: {cf.GetNumberColumns()}")