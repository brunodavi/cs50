from PIL import Image, ImageFilter

before = Image.open('tower.bmp')
after = before.filter(ImageFilter.BlueBox(1))
after.save("out.bmp")