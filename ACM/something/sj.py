import pandas as pd

df = pd.read_csv('stock.csv')

for i in range(len(df)):
    df.loc[i, 'time'] = df.loc[i, 'time'][:-6]

df.to_csv('nstock.csv', index=False, header=False)