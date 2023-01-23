import numpy as np
import matplotlib.pyplot as plt
 

def create_ghaph(serial,mutex,rwlock,case_no):
    # set width of bar
    barWidth = 0.25
    fig = plt.subplots(figsize =(12, 8))
    
    # set height of bar
    # serial = [12, 30, 1, 8, 22]
    # mutex = [28, 6, 16, 5, 10]
    # rwlock = [29, 3, 24, 25, 17]
    
    # Set posserialion of bar on X axis
    br1 = np.arange(len(serial))
    br2 = [x + barWidth for x in br1]
    br3 = [x + barWidth for x in br2]
    
    # Make the plot
    plt.bar(br1, serial, color ='r', width = barWidth,
            edgecolor ='grey', label ='serial')
    plt.bar(br2, mutex, color ='g', width = barWidth,
            edgecolor ='grey', label ='mutex')
    plt.bar(br3, rwlock, color ='b', width = barWidth,
            edgecolor ='grey', label ='rwlock')
    
    # Adding Xticks
    plt.title(f"Average Execution Time Vs Thread Count: {case_no}")
    plt.xlabel('No of threads', fontweight ='bold', fontsize = 15)
    plt.ylabel('Average execution time', fontweight ='bold', fontsize = 15)
    plt.xticks([r + barWidth for r in range(len(serial))],
            ['1', '2', '4', '8'])
    
    plt.legend()
    #plt.show()
    plt.savefig(f'Graph{ case_no}.png')

# serial=[0.006911 ,0.000000 ,0.000000 ,0.000000]
# mutex=[0.003430 ,0.015894 ,0.051085 ,0.129724 ]
# rwlock=[0.003173 ,0.013531 ,0.016545 ,0.018594]

# serial=[0.009752 ,0.000000 ,0.000000 ,0.000000 ]
# mutex=[0.006505 ,0.024640 ,0.058241 ,0.152421]
# rwlock=[0.006909 ,0.038761 ,0.046173 ,0.053319]

serial=[0.022185 ,0.000000 ,0.000000 ,0.000000]
mutex=[0.021694 ,0.050680 ,0.083273 ,0.146513]
rwlock=[0.022708 ,0.084209 ,0.115878 ,0.125341 ]

create_ghaph(serial,mutex,rwlock,"Case 03")