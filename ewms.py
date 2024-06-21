import pandas as pd
import numpy as np


ilist = [1,2,3,4]

print(list(reversed(ilist)))

here = pd.DataFrame(reversed(ilist))


print(here.ewm(alpha=.5).mean().iloc[-1].values, np.mean(here))