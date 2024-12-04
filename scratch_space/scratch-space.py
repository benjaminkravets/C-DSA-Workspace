import pandas as pd

df = pd.read_csv("large.csv", engine="c")

df = [df.columns.tolist()] + df.to_numpy().tolist()


print(df)