all:
	make debug
	make release
	make app_

update:
	git pull

debug: libvproperty_d libvproperty_gui_d libvproperty_test_d

release: libvproperty libvproperty_gui libvproperty_test

libvproperty_d:
	cd lib && \
	qmake libvproperty.pro CONFIG+=debug && \
	make && \
	make clean && \
	cd ..

libvproperty_gui_d:
	cd lib && \
	qmake libvproperty_gui.pro CONFIG+=debug && \
	make && \
	make clean && \
	cd ..

libvproperty_test_d:
	cd lib && \
	qmake libvproperty_test.pro CONFIG+=debug && \
	make && \
	make clean && \
	cd ..

libvproperty:
	cd lib && \
	qmake libvproperty.pro && \
	make && \
	make clean && \
	cd ..

libvproperty_gui:
	cd lib && \
	qmake libvproperty_gui.pro && \
	make && \
	make clean && \
	cd ..

libvproperty_test:
	cd lib && \
	qmake libvproperty_test.pro && \
	make && \
	make clean && \
	cd ..

app_:
	cd app && qmake && make && make clean && cd ..

clean:
	find -type d -name 'build-*'    -exec rm -r {} \;
	find -type f -name '*.o'        -delete
	find -type f -name '*.pro.user' -delete
	find -type f -name 'Makefile*'  -delete
