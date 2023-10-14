cmake_minimum_required(VERSION 3.22)
project(quant_math)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)
enable_testing()

set(SRCS_PRICER pricer/ContinousAssetModelPricer.cpp pricer/ContinousAssetModelPricer.h
        pricer/DiscreteAssetModelPricer.cpp pricer/DiscreteAssetModelPricer.h
        pricer/GeometricBrownianMotionPricer.h pricer/MonteCarloPricer.h
        pricer/BlackScholes.cpp pricer/BlackScholes.h
        pricer/MonteCarloVarianceReductionPricer.h)
set(SRCS_MATH math_util/operations.cpp math_util/operations.h math_util/stat.cpp math_util/stat.h)
set(SRCS_OPTIONS options/DigitalOption.h options/EuropeanOption.h options/Option.h options/Pricable.h
        options/PricePathDependentOption.h options/PricePathDependentPricable.h
        options/PricePathIndependentOption.h options/PricePathIndependentPricable.h)
set(SRCS_TEST test/math_util/test_operations.cpp test/math_util/test_stat.cpp test/pricer/test_BlackScholes.cpp
        test/options/test_EuropeanOption.cpp test/pricer/test_MonteCarloPricer.cpp test/pricer/test_MonteCarloVarianceReductionPricer.cpp pricer/gpu/kernel.cu pricer/gpu/kernel.cuh)

add_executable(${PROJECT_NAME} main.cpp ${SRCS_PRICER} ${SRCS_MATH} ${SRCS_TEST} ${SRCS_OPTIONS})

target_link_libraries(${PROJECT_NAME} PRIVATE GTest::gtest_main )
