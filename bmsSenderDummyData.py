import random
import json

for i in range(10):
    # print("\n{\"Temperature\":{},\"SOC\":{}}\n".format(48.00, 58.00));
    print(json.dumps({'Temperature':random.randint(10,100), 'SOC':random.randint(10,100)}))
    
    