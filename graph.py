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

serial=[0.003456 ,0.000000 ,0.000000 ,0.000000]
mutex=[0.004028 ,0.007608 ,0.027570 ,0.101914]
rwlock=[0.004069 ,0.005317 ,0.010916 ,0.012172]

serial2=[0.003858 ,0.000000 ,0.000000 ,0.000000 ]
mutex2=[0.004073 ,0.011368 ,0.037706 ,0.124409 ]
rwlock2=[0.004088 ,0.026378 ,0.035390 ,0.037602]

serial3=[0.016492 ,0.000000 ,0.000000 ,0.000000]
mutex3=[0.015702 ,0.032331 ,0.071194 ,0.146476]
rwlock3=[0.015785 ,0.065261 ,0.098415 ,0.108093 ]

create_ghaph(serial,mutex,rwlock,"Case 01")
create_ghaph(serial2,mutex2,rwlock2,"Case 02")
create_ghaph(serial3,mutex3,rwlock3,"Case 03")