#
#Makefile
#
CC	=		gcc			# コンパイラ

SOURCES	=	main.c			\
			ReadMesh.c		\
			ReadCond.c		\
			CalcElem.c		\
			CalcMatrix.c	\
			CalcBand.c		\
			SetBound.c		\
			Coef.c			\
			Gauss.c			

OBJECTS	=	$(SOURCES:.c=.o)	# [.obj] file
TARGET	=	fem2d				# 実行フェイル名

# 生成規則

# 実行ファイル生成コマンド
# .obj のリンクを行う
$(TARGET):	$(OBJECTS)
			$(CC) -o $@ $(OBJECTS)
# サフィックスルール
# .c から .oの作成
.c.o:
			$(CC) -c -Wall $< -o $@

# オブジェクトファイルの削除
clean:
			rm *.o *~ $(TARGET) -rf
