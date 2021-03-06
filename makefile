define makelib # $(1)filename, $(2)config
	cd lib && \
	qmake $(1) CONFIG+=$(2) && \
	make && \
	make clean && \
	cd ..
endef

first: all

all: debug release app_

update:
	git pull

debug: libvproperty_d libvproperty_test_d

release: libvproperty libvproperty_test

libvproperty_d:
	$(call makelib,libvproperty.pro,debug)

libvproperty_test_d:
	$(call makelib,libvproperty_test.pro,debug)

libvproperty:
	$(call makelib,libvproperty.pro,release)

libvproperty_test:
	$(call makelib,libvproperty_test.pro,release)

app_:
	cd app && qmake && make && make clean && cd ..

clean:
	find -type d -name 'build-*'    -exec rm -r {} \; | true
	find -type f -name '*.o'        -delete
	find -type f -name '*.pro.user' -delete
	find -type f -name 'Makefile*'  -delete
