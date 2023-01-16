import pandas as pd
df = pd.read_excel(r'Tmp.xlsx',index_col=0)
print(df2)
tmpstr = df.to_json(orient='index')
print(tmpstr.replace("\"x\"","true").replace("null","false"))
