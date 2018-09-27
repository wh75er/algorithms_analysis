import numpy as np
import matplotlib.pyplot as plt

fig = plt.figure()
ax = fig.add_subplot(111)

## the data
N = 10
levensteinMeans = [1160.69, 3386.68, 6894.87, 11388.15, 16256.26, 22788.15, 
            30624.30, 39347.78, 49090.74, 60138.4]
#menStd =   [2, 3, 4, 1, 2]
damerauMeans = [1104.36, 3715.57, 7948.93, 13927.45, 21693.57, 30997.78,
                42215.05, 55002.26, 69462.62, 85606.46]
#womenStd =   [3, 5, 2, 3, 3]

## necessary variables
ind = np.arange(N)                # the x locations for the groups
width = 0.35                      # the width of the bars

## the bars
rects1 = ax.bar(ind, levensteinMeans, width,
                color='black',
                #yerr=menStd,
                error_kw=dict(elinewidth=2,ecolor='red'))

rects2 = ax.bar(ind+width, damerauMeans, width,
                    color='red',
                    #yerr=womenStd,
                    error_kw=dict(elinewidth=2,ecolor='black'))

ymin = 0
ymax = max(max(levensteinMeans), max(damerauMeans))

# axes and labels
ax.set_xlim(-width,len(ind)+width)
ax.set_ylim(ymin,ymax+1000)
ax.set_ylabel('Time(macrosec)')
ax.set_title('Working time')
xTickMarks = [str(i) for i in range(100,1100, 100)]
ax.set_xticks(ind+width)
xtickNames = ax.set_xticklabels(xTickMarks)
plt.setp(xtickNames, rotation=45, fontsize=10)

## add a legend
ax.legend( (rects1[0], rects2[0]), ('Levenstein', 'Damerau') )

plt.show()
