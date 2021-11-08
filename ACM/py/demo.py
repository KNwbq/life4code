from PIL import ImageFilter
from PIL import Image
from PIL import ImageEnhance
img = Image.open("bird.jpg")
nimg = img.filter(ImageFilter.BLUR)
nnimg = ImageEnhance.Contrast(nimg)
nnimg.enhance(20).save('birdnestEnContrast.jpg')