# 描述

打包程序参考2篇文章：
1. pyinstaller https://blog.csdn.net/libaineu2004/article/details/112612421

2. pip install cx_freeze

二者都需在虚拟环境中进行，否则打包后的程序很大且会报很麻烦的错误。

# 步骤与注意事项
首先创建虚拟环境，然后进行打包。

1.遇到了：ImportError: OpenCV loader: missing configuration file: ['config-3.6.py', 'config-3.py']. Check OpenCV installation
解决：升级cv2 pyinstaller后依然无法解决，根据opencv/opencv-python#569 发现是cv2版本更新，
新的打包程序不支持了导致。降级即可。

2.闪退：运行程序后，加载图片后闪退，安装pip install cx_freeze，打包后执行发现是程序报错
AttributeError: module 'matplotlib' has no attribute 'image'
解决：程序中加入：
import matplotlib
import matplotlib.image as img

* 读取的文件必须是转换成HU值之后的raw文件。（文件尺寸：1024 * 1024 * 300， 数据类型：int16）

* 检测后的结果会相应保存在运行程序的当前目录下，请妥善保存，下次再检测raw文件会将上一次生成的结果（png格式）覆盖掉。
