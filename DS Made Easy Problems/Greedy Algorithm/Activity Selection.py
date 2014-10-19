def activitySelection(start,end,n):
    i=0
    print 'Maximum Activites that can be scheduled are: '
    print i+1
    for j in xrange(1,n):
        if(start[j]>=end[i]):
            print j+1
            i=j
    
def sort(start,end,n):
    swapped=1
    for cntr in xrange(n-1,-1,-1):
        if(swapped):
            swapped=0
            for i in xrange(0,cntr):
                if(end[i]>end[i+1]):
                    swapped=1
                    temp = end[i]
                    end[i] = end[i+1]
                    end[i+1] = temp

                    temp = start[i]
                    start[i] = start[i+1]
                    start[i+1] = temp

def main():
    n = input("Enter Number of Jobs: ")
    start = [None]*n
    end = [None]*n
    for i in xrange(0,n):
        start[i]=input()
        end[i]=input()
    sort(start,end,n)
    #for i in xrange(0,n):
     #   print start[i],end[i]
    activitySelection(start,end,n)
    raw_input('Press <ENTER>')

main()
