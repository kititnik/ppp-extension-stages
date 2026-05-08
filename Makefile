# =========================
# ПАРАМЕТРЫ ЗАПУСКА
# =========================

USE_DOCKER ?= yes
ARGS ?=

ROOT := .
SRC_DIR := $(ROOT)/src
BUILD_DIR := $(ROOT)/build
BIN := $(BUILD_DIR)/app.out

# =========================
# PPP Containers
# =========================
PPSCL_DIR := libs
PPSCL_SOURCES := $(shell find $(PPSCL_DIR) -name '*.c')
PPSCL_INCLUDE := $(addprefix -I,$(shell find $(PPSCL_DIR) -type d))

# =========================
# PPClang
# =========================
ifeq ($(USE_DOCKER),yes)
    PPC_IMAGE := ppclang-new
    DOCKER := docker run --rm -it \
        --platform linux/amd64 \
        -v $(ROOT):/work \
        -w /work \
        $(PPC_IMAGE)
    PPCLANG := $(DOCKER) bash -i -c "ppclang"
else
	PPCLANG := ppclang
endif

PPC_SRC := $(shell find $(SRC_DIR) -name '*.c')

# =========================
# ОБЩИЕ ЦЕЛИ
# =========================
.PHONY: all build run clean info

all: build

# =========================
# СБОРКА
# =========================
build:
	@mkdir -p $(BUILD_DIR)
ifeq ($(USE_DOCKER),yes)
	$(DOCKER) bash -i -c "ppclang $(PPC_SRC) $(PPSCL_SOURCES) $(PPSCL_INCLUDE) -I$(ROOT)/include -o $(BIN)"
else
	ppclang $(PPC_SRC) $(PPSCL_SOURCES) $(PPSCL_INCLUDE) -I$(ROOT)/include -o $(BIN)
endif

# =========================
# ЗАПУСК
# =========================
run:
ifeq ($(USE_DOCKER),yes)
	$(DOCKER) bash -i -c "./$(BIN) $(ARGS)"
else
	./$(BIN) $(ARGS)
endif

# =========================
# СЛУЖЕБНОЕ
# =========================
clean:
	rm -rf $(BUILD_DIR)

info:
	@echo "Src   : $(SRC_DIR)"
	@echo "Bin   : $(BIN)"

