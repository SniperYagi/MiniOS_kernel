deps_config := \
	devices/Kconfig \
	arch/arm/Kconfig \
	Kconfig \

include/config/auto.conf: $(deps_config)

ifneq "$(ARCH)" "arm"
include/config/auto.conf: FORCE
endif

$(deps_config): ;
