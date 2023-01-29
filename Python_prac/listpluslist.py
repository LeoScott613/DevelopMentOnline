salary=[1000,2000,3000]
times=[0.3,0.4,0.1]
result=[]
for i in range(0,3):
    result.append(salary[i]*times[i])

for res in result:
    print(res,end=' ')