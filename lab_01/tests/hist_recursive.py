import numpy as np
import matplotlib.pyplot as plt

fig = plt.figure()
ax = fig.add_subplot(111)

## the data
N = 9
levensteinMeans = [6.29, 5.99, 6.98, 7.25, 8.40, 8.49, 10.38, 10.52,
                    11.47]
#menStd =   [2, 3, 4, 1, 2]
damerauMeans = [2.35, 2.66, 3.79, 4.45, 5.94, 7.53, 9.13, 9.76, 10.26]
#womenStd =   [3, 5, 2, 3, 3]
recursiveMeans = [1.84, 2.50, 5.66, 17.52, 81.24, 364.98, 2115.06, 9498.17,
                48454.87]

## necessary variables
ind = np.arange(N)                # the x locations for the groups
width = 0.20                      # the width of the bars

## the bars
rects1 = ax.bar(ind, levensteinMeans, width,
                color='black',
                #yerr=menStd,
                error_kw=dict(elinewidth=2,ecolor='red'))

rects2 = ax.bar(ind+width, damerauMeans, width,
                    color='red',
                    #yerr=womenStd,
                    error_kw=dict(elinewidth=2,ecolor='black'))

rects3 = ax.bar(ind+width+width, recursiveMeans, width,
                    color='blue',
                    #yerr=womenStd,
                    error_kw=dict(elinewidth=2,ecolor='blue'))


ymin = 0
ymax = max(max(levensteinMeans), max(damerauMeans))

# axes and labels
ax.set_xlim(-width,len(ind)+width)
ax.set_ylim(ymin,ymax+10)
ax.set_ylabel('Time(macrosec)')
ax.set_title('Working time')
xTickMarks = [str(i) for i in range(0,9, 1)]
ax.set_xticks(ind+width)
xtickNames = ax.set_xticklabels(xTickMarks)
plt.setp(xtickNames, rotation=45, fontsize=10)

## add a legend
ax.legend( (rects1[0], rects2[0], rects3[0]), 
        ('Levenstein', 'Damerau', 'Recursive') )

plt.show()
