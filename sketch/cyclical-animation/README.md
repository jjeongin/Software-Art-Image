# Cyclical Animation

https://user-images.githubusercontent.com/68997923/163732544-f6fa9a15-37f6-45de-a833-ed4ce024e89c.mov

## Description
Cyclical animation of a flower blooming repititively. To make the overall visual more interesting and dynamic, I added overlapping layers of the same video looping over and over with the variation of color and transparency as the time passes. The endlessly continued looping and the slightly missed timing between the fading and looping of the videos add unique a rhythm to the visual and provoke tension. Each differently tinted grid is composed together to create one whole image. 

First, I started by converting the [original gif image](https://gfycat.com/amp/alertwarlikeass-flower-blooming-gif) to the mp4 format so that I can handle it more easily in openframeworks. By wrapping the current time with a sin function, I was able to create a looping image over and over. Then, I mapped each sinTime to the value that is between 0 to 255 so that I can use it for ofColor. I manually tuned the values and came up with a unique color scheme. I applied reversed alpha value to each diagonal grid so that it alternates.
