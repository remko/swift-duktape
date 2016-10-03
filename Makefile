SOURCES_DIR=Sources/CDuktape

DUKTAPE_UPSTREAM_FILE=duktape-1.5.1.tar.xz
DUKTAPE_UPSTREAM_URL=http://duktape.org/$(DUKTAPE_UPSTREAM_FILE)

DUKTAPE_FILES=duktape.c duktape.h duk_config.h CDuktape.c include/CDuktape.h
DUKTAPE_TARGET_FILES=$(addprefix $(SOURCES_DIR)/, $(DUKTAPE_FILES))
DUKTAPE_COPYRIGHT_FILES=AUTHORS.duktape.rst LICENSE.duktape.txt

all: $(DUKTAPE_TARGET_FILES) $(DUKTAPE_COPYRIGHT_FILES)
	swift build

$(SOURCES_DIR)/duktape.c: Upstream/src/duktape.c
	cp $< $@

$(SOURCES_DIR)/duktape.h: Upstream/src/duktape.h
	cp $< $@

$(SOURCES_DIR)/duk_config.h: Upstream/src/duk_config.h
	cp $< $@

$(SOURCES_DIR)/include/CDuktape.h $(SOURCES_DIR)/CDuktape.c Tests/CDuktapeTests/CompletenessTests.swift: Upstream/src/duktape.h create_wrapper.rb
	./create_wrapper.rb $< \
		$(SOURCES_DIR)/include/CDuktape.h \
		$(SOURCES_DIR)/CDuktape.c \
		Tests/DuktapeTests/CompletenessTests.swift

AUTHORS.duktape.rst: Upstream/AUTHORS.rst
	cp $< $@

LICENSE.duktape.txt: Upstream/LICENSE.txt
	cp $< $@

Upstream/%: $(DUKTAPE_UPSTREAM_FILE)
	mkdir -p Upstream
	cd Upstream && tar xJmf ../$(DUKTAPE_UPSTREAM_FILE) --strip-components=1

$(DUKTAPE_UPSTREAM_FILE): 
	curl -O http://duktape.org/duktape-1.5.1.tar.xz

.PHONY: check
check: all
	swift test
