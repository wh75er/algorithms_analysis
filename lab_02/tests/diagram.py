import numpy as np
import matplotlib.pyplot as plt

fig = plt.figure()
ax = fig.add_subplot(111)

## the data
N = 10
ClassicMeans = [20.077, 158.613, 536.736, 1277.363, 2508.538, 4878.377,
                     7778.614, 11597.817, 16712.889, 23102.137]
#menStd =   [2, 3, 4, 1, 2]
EnhancedMeans = [20.859, 154.072, 516.737, 1229.492, 2408.629, 4685.910,
                        7495.057, 11170.562, 16070.812, 22225.149]
MultiplyMeans = [25.865, 201.215, 678.302, 1675.234, 3294.885, 6107.689, 9871.546,
                    14822.127, 21545.400, 29986.602]
#womenStd =   [3, 5, 2, 3, 3]

## necessary variables
ind = np.arange(N)                # the x locations for the groups
width = 0.20                      # the width of the bars

## the bars
rects1 = ax.bar(ind, ClassicMeans, width,
                        color='black',
                                        #yerr=menStd,
                                                        error_kw=dict(elinewidth=2,ecolor='red'))

rects2 = ax.bar(ind+width, EnhancedMeans, width,
                            color='red',
                                                #yerr=womenStd,
                                                                    error_kw=dict(elinewidth=2,ecolor='black'))

rects3 = ax.bar(ind+width+width, MultiplyMeans, width,
                            color='blue',
                                                #yerr=womenStd,
                                                                    error_kw=dict(elinewidth=2,ecolor='blue'))


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
ax.legend( (rects1[0], rects2[0], rects3[0]), ('ClassicWin', 'Enhanced', 'ClassicAlgorithm') )

plt.show()

