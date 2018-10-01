class linkedlist:
    def __init__(self, dataval=None):
        self.dataval = dataval
        self.nextval = None

class headnode:
    def __init__(self):
        self.lead = None
        
print("insert months:\n")
leadnode = headnode()
for i in range(10):
    a = input("enter: \n")
    if leadnode.lead == None:
        leadnode.lead = linkedlist(a)
        obj = leadnode.lead
    else:
        obj1 = linkedlist(a)
        obj.nextval = obj1
        obj = obj1

print("\nprint months:\n")

printnode = leadnode.lead
while printnode is not None:
    print(printnode.dataval)
    printnode = printnode.nextval
    


