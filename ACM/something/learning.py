import pandas as pd
import numpy as np
df = pd.DataFrame([[1, 2, 3, 4], [5, 1.2, 32.2, 12.3],[1,1,1,1]],index=list('abc'),columns=list('1234'))
df['5'] = pd.Series()
for x in df.columns[:-1]:
    print(x)

for row in df.index:
    df.loc[row,'5'] = sum([df.loc[row, x] for x in df.columns[-2:-1]]) 

print(df)
