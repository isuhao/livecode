# Android options
ANDROID_NDK=${ANDROID_NDK:-"$HOME/Workspace/livecode/sdks/android-ndk"}
ANDROID_PLATFORM=${ANDROID_PLATFORM:-android-8}

# Has a full, custom toolchain been specified?
#  AR, CC, CXX, LINK, OBJCOPY, RANLIB, STRIP
if [ ! -z "${OBJCOPY}" ] ; then
	ANDROID_CC="${CC}"
	ANDROID_CXX="${CXX}"
	ANDROID_LINK="${LINK}"
else
	# Attempt to set up the toolchain automatically
	if [ -z "${ANDROID_TOOLCHAIN}" ] ; then
		ANDROID_TOOLCHAIN="${HOME}/android/toolchain/standalone/bin/arm-linux-androideabi"
	fi

	ANDROID_CC_NAME=${ANDROID_CC_NAME:-clang}
	ANDROID_CXX_NAME=${ANDROID_CXX_NAME:-clang}

	ANDROID_CC="${ANDROID_TOOLCHAIN}-${ANDROID_CC_NAME}"
	ANDROID_CXX="${ANDROID_TOOLCHAIN}-${ANDROID_CXX_NAME}"
	ANDROID_LINK="${ANDROID_TOOLCHAIN}-${ANDROID_CXX_NAME}"
	export AR="${ANDROID_TOOLCHAIN}-ar"
	export OBJCOPY="${ANDROID_TOOLCHAIN}-objcopy"
	export RANLIB="${ANDROID_TOOLCHAIN}-ranlib"
	export STRIP="${ANDROID_TOOLCHAIN}-strip"
fi

# Android architectures
export ARCHS="armv6"
