import sys
from osgeo import ogr
import numpy as np
import pandas as pd
# question 1
print("begin")
fn = r'data/ne_50m_populated_places.shp'
ds = ogr.Open(fn,0)
if ds is None:
    sys.exit('Could not open {0}'.format(fn))
lyr = ds.GetLayer(0)
i=0
dflist=[]
for feat in lyr:
    name = feat.GetField('NAME')
    pop = feat.GetField('POP_MAX')
    latitude = feat.GetField('LATITUDE')
    longitude = feat.GetField('LONGITUDE')
    country = feat.GetField('SOV0NAME')
    # print(name,longitude,latitude,country,pop)
    dflist.append([name,longitude,latitude,country,pop])
    i +=1
head=["city","longitude","latitude","country","max_population"]
df = pd.DataFrame(dflist,columns=head)
sfn=r"data/result.txt"
df.to_csv(sfn,index=False)

# question 2

df=df.sort_values(by="max_population",ascending=False)
print(df.head(10))
print("max population top 10 is:")
print(list(df.head(10)["city"]))

# question 3
# count
def getcount(df,key,rg=(0,0)):
    assert len(rg)==2
    assert rg[0]<rg[1]
    tmp = df.loc[(df[key]>=rg[0]) & (df[key]<rg[1])]
    return tmp.shape[0]
rangedict={
    "less than 10":(0,100000),
    "10 to 50":(100000,500000),
    "50 to 100":(500000,1000000),
    "100 to 200":(1000000,2000000),
    "200 to 500":(2000000,5000000),
    "more than 500":(5000000,sys.maxsize),
}
counters=[]
names=[]
for key,value in rangedict.items():
    count=getcount(df,"max_population",value)
    print(key,":",count)
    counters.append(count)
    names.append(key)
# draw bar
import matplotlib.pyplot as plt
fig=plt.figure("city counts",figsize=(9,6))
fig.tight_layout()
ax=fig.add_subplot(111)
ax.bar(names,counters)
plt.xlabel("population")
plt.ylabel("count")
# ylable="counts",xlable="population"
plt.savefig("data/result.png")
# plt.show()
del ds