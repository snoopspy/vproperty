define makelib # $(1)filename, $(2)config
	cd lib && \
	qmake $(1) CONFIG+=$(2) && \
	make && \
	make clean && \
	cd ..
endef

all:
	make debug
	make release
	make app_

update:
	git pull

debug: libvproperty_d libvproperty_gui_d libvproperty_test_d libvproperty_gui_test_d

release: libvproperty libvproperty_gui libvproperty_test libvproperty_gui_test

libvproperty_d:
	$(call makelib,libvproperty.pro,debug)

libvproperty_gui_d:
	$(call makelib,libvproperty_gui.pro,debug)

libvproperty_test_d:
	$(call makelib,libvproperty_test.pro,debug)

libvproperty_gui_test_d:
	$(call makelib,libvproperty_gui_test.pro,debug)

libvproperty:
	$(call makelib,libvproperty.pro,release)

libvproperty_gui:
	$(call makelib,libvproperty_gui.pro,release)

libvproperty_test:
	$(call makelib,libvproperty_test.pro,release)

libvproperty_gui_test:
	$(call makelib,libvproperty_gui_test.pro,release)

app_:
	cd app && qmake && make && make clean && cd ..

clean:
	find -type d -name 'build-*'    -exec rm -r {} \;
	find -type f -name '*.o'        -delete
	find -type f -name '*.pro.user' -delete
	find -type f -name 'Makefile*'  -delete
