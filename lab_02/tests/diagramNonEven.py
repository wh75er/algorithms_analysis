import numpy as np
import matplotlib.pyplot as plt

fig = plt.figure()
ax = fig.add_subplot(111)

## the data
N = 10
ClassicMeans = [20.809, 161.322, 541.239, 1284.754, 2528.653, 4918.674,
                     7833.712, 11725.979, 16774.922, 23189.963]
#menStd =   [2, 3, 4, 1, 2]
EnhancedMeans = [21.282, 156.754, 525.954, 1236.969, 2422.614, 4727.957,
                         7528.168, 11282.570, 16120.746, 22264.232]
#womenStd =   [3, 5, 2, 3, 3]

## necessary variables
ind = np.arange(N)                # the x locations for the groups
width = 0.35                      # the width of the bars

## the bars
rects1 = ax.bar(ind, ClassicMeans, width,
                        color='black',
                                        #yerr=menStd,
                                                        error_kw=dict(elinewidth=2,ecolor='red'))

rects2 = ax.bar(ind+width, EnhancedMeans, width,
                            color='red',
                                                #yerr=womenStd,
                                                                    error_kw=dict(elinewidth=2,ecolor='black'))

ymin = 0
ymax = max(max(ClassicMeans), max(EnhancedMeans))

# axes and labels
ax.set_xlim(-width,len(ind)+width)
ax.set_ylim(ymin,ymax+1000)
ax.set_ylabel('Time(microsec)')
ax.set_title('Working time')
xTickMarks = [str(i) for i in range(100,1100, 100)]
ax.set_xticks(ind+width)
xtickNames = ax.set_xticklabels(xTickMarks)
plt.setp(xtickNames, rotation=45, fontsize=10)

## add a legend
ax.legend( (rects1[0], rects2[0]), ('Classic', 'Enhanced') )

plt.show()

