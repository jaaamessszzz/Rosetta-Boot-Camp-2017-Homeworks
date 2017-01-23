import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import os
import numpy as np

df = pd.read_csv('/Users/jameslucas/Box_Sync/Kortemme_Lab/Dry_Lab/RosettaBootCamp_Homeworks/hw_set_2/hw5/fib_loop_times.csv')

sns.set_style("white", {'axes.grid': True})
sns.set_context("notebook", font_scale=1.5, rc={"lines.linewidth": 1.5})
sns.despine()

fig,ax = plt.subplots(figsize=(10,10))
sns.regplot(x='nth fibonacci number',
            y='Time (seconds)',
            data=df,
            ax=ax,
            fit_reg=False
            )

title = 'Running Times for 10000x Iterative Fibonacci Loop'
ax.set_xlabel('nth Fibonacci Number', fontsize = 20, y=0)
ax.set_ylabel('Time (seconds)', fontsize = 20)
fig_title = ax.set_title(title, fontsize = 28, y = 1.03)

fig.savefig('20161206-%s.png'%('_'.join(title.split())),
            bbox_inches='tight',
            # bbox_extra_artists=(fig_title),
            dpi=300
            )



