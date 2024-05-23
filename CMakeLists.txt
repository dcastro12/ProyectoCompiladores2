cmake_minimum_required(VERSION 3.8)
project(Expr)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(FLEX)
find_package(BISON)

FLEX_TARGET(ExprLexer ExprLexerImpl.l
            ${CMAKE_CURRENT_BINARY_DIR}/ExprLexerImpl.cpp
            DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/ExprLexerImpl.h
            )

BISON_TARGET(ExprParser ExprParserImpl.y
            ${CMAKE_CURRENT_BINARY_DIR}/ExprParserImpl.cpp
            DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/ExprParserImpl.hpp
            )

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CMAKE_SOURCE_DIR})

add_executable(${PROJECT_NAME}
    ${FLEX_ExprLexer_OUTPUTS}
    ${BISON_ExprParser_OUTPUTS}
    ExprLexer.hpp
    ExprLexer.cpp
    ExprParser.hpp
    ExprParser.cpp
    main.cpp
)

# Agregar un objetivo personalizado para ejecutar los archivos de prueba
add_custom_target(run_tests ALL

    COMMAND ${CMAKE_COMMAND} -E echo "Probando AddIntInt.lpp"
    COMMAND ${PROJECT_BINARY_DIR}/${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/tests/AddIntInt.lpp 2>/dev/null && ${CMAKE_COMMAND} -E echo "✅ AddIntInt.lpp pasado" || ${CMAKE_COMMAND} -E echo "❌ AddIntInt.lpp fallido"
    COMMAND ${CMAKE_COMMAND} -E echo ""

    COMMAND ${CMAKE_COMMAND} -E echo "Probando BoolTest.lpp"
    COMMAND ${PROJECT_BINARY_DIR}/${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/tests/BoolTest.lpp 2>/dev/null && ${CMAKE_COMMAND} -E echo "✅ BoolTest.lpp pasado" || ${CMAKE_COMMAND} -E echo "❌ BoolTest.lpp fallido"
    COMMAND ${CMAKE_COMMAND} -E echo ""

    COMMAND ${CMAKE_COMMAND} -E echo "Probando CharTest.lpp"
    COMMAND ${PROJECT_BINARY_DIR}/${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/tests/CharTest.lpp 2>/dev/null && ${CMAKE_COMMAND} -E echo "✅ CharTest.lpp pasado" || ${CMAKE_COMMAND} -E echo "❌ CharTest.lpp fallido"
    COMMAND ${CMAKE_COMMAND} -E echo ""

    COMMAND ${CMAKE_COMMAND} -E echo "Probando fibonacci.lpp"
    COMMAND ${PROJECT_BINARY_DIR}/${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/tests/fibonacci.lpp 2>/dev/null && ${CMAKE_COMMAND} -E echo "✅ fibonacci.lpp pasado" || ${CMAKE_COMMAND} -E echo "❌ fibonacci.lpp fallido"
    COMMAND ${CMAKE_COMMAND} -E echo ""

    COMMAND ${CMAKE_COMMAND} -E echo "Probando gcd.lpp"
    COMMAND ${PROJECT_BINARY_DIR}/${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/tests/gcd.lpp 2>/dev/null && ${CMAKE_COMMAND} -E echo "✅ gcd.lpp pasado" || ${CMAKE_COMMAND} -E echo "❌ gcd.lpp fallido"
    COMMAND ${CMAKE_COMMAND} -E echo ""

    COMMAND ${CMAKE_COMMAND} -E echo "Probando HolaMundo.lpp"
    COMMAND ${PROJECT_BINARY_DIR}/${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/tests/HolaMundo.lpp 2>/dev/null && ${CMAKE_COMMAND} -E echo "✅ HolaMundo.lpp pasado" || ${CMAKE_COMMAND} -E echo "❌ HolaMundo.lpp fallido"
    COMMAND ${CMAKE_COMMAND} -E echo ""

    COMMAND ${CMAKE_COMMAND} -E echo "Probando SelectionSort.lpp"
    COMMAND ${PROJECT_BINARY_DIR}/${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/tests/SelectionSort.lpp 2>/dev/null && ${CMAKE_COMMAND} -E echo "✅ SelectionSort.lpp pasado" || ${CMAKE_COMMAND} -E echo "❌ SelectionSort.lpp fallido"
    COMMAND ${CMAKE_COMMAND} -E echo ""

    COMMAND ${CMAKE_COMMAND} -E echo "Probando TestArray1DInt.lpp"
    COMMAND ${PROJECT_BINARY_DIR}/${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/tests/TestArray1DInt.lpp 2>/dev/null && ${CMAKE_COMMAND} -E echo "✅ TestArray1DInt.lpp pasado" || ${CMAKE_COMMAND} -E echo "❌ TestArray1DInt.lpp fallido"
    COMMAND ${CMAKE_COMMAND} -E echo ""

    COMMAND ${CMAKE_COMMAND} -E echo "Probando TestMientras.lpp"
    COMMAND ${PROJECT_BINARY_DIR}/${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/tests/TestMientras.lpp 2>/dev/null && ${CMAKE_COMMAND} -E echo "✅ TestMientras.lpp pasado" || ${CMAKE_COMMAND} -E echo "❌ TestMientras.lpp fallido"
    COMMAND ${CMAKE_COMMAND} -E echo ""

    COMMAND ${CMAKE_COMMAND} -E echo "Probando TestPara.lpp"
    COMMAND ${PROJECT_BINARY_DIR}/${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/tests/TestPara.lpp 2>/dev/null && ${CMAKE_COMMAND} -E echo "✅ TestPara.lpp pasado" || ${CMAKE_COMMAND} -E echo "❌ TestPara.lpp fallido"
    COMMAND ${CMAKE_COMMAND} -E echo ""

    COMMAND ${CMAKE_COMMAND} -E echo "Probando TestRepita.lpp"
    COMMAND ${PROJECT_BINARY_DIR}/${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/tests/TestRepita.lpp 2>/dev/null && ${CMAKE_COMMAND} -E echo "✅ TestRepita.lpp pasado" || ${CMAKE_COMMAND} -E echo "❌ TestRepita.lpp fallido"
    COMMAND ${CMAKE_COMMAND} -E echo ""

    COMMAND ${CMAKE_COMMAND} -E echo "Probando TestSi.lpp"
    COMMAND ${PROJECT_BINARY_DIR}/${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/tests/TestSi.lpp 2>/dev/null && ${CMAKE_COMMAND} -E echo "✅ TestSi.lpp pasado" || ${CMAKE_COMMAND} -E echo "❌ TestSi.lpp fallido"
    COMMAND ${CMAKE_COMMAND} -E echo ""

    COMMAND ${CMAKE_COMMAND} -E echo "Probando TestSubprg1.lpp"
    COMMAND ${PROJECT_BINARY_DIR}/${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/tests/TestSubprg1.lpp 2>/dev/null && ${CMAKE_COMMAND} -E echo "✅ TestSubprg1.lpp pasado" || ${CMAKE_COMMAND} -E echo "❌ TestSubprg1.lpp fallido"
    COMMAND ${CMAKE_COMMAND} -E echo ""

    COMMAND ${CMAKE_COMMAND} -E echo "Probando TestSubprg2.lpp"
    COMMAND ${PROJECT_BINARY_DIR}/${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/tests/TestSubprg2.lpp 2>/dev/null && ${CMAKE_COMMAND} -E echo "✅ TestSubprg2.lpp pasado" || ${CMAKE_COMMAND} -E echo "❌ TestSubprg2.lpp fallido"
    COMMAND ${CMAKE_COMMAND} -E echo ""

    COMMAND ${CMAKE_COMMAND} -E echo "Probando TestSubprg5.lpp"
    COMMAND ${PROJECT_BINARY_DIR}/${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/tests/TestSubprg5.lpp 2>/dev/null && ${CMAKE_COMMAND} -E echo "✅ TestSubprg5.lpp pasado" || ${CMAKE_COMMAND} -E echo "❌ TestSubprg5.lpp fallido"
    COMMAND ${CMAKE_COMMAND} -E echo ""

    COMMAND ${CMAKE_COMMAND} -E echo "Probando TestSubprg8.lpp"
    COMMAND ${PROJECT_BINARY_DIR}/${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/tests/TestSubprg8.lpp 2>/dev/null && ${CMAKE_COMMAND} -E echo "✅ TestSubprg8.lpp pasado" || ${CMAKE_COMMAND} -E echo "❌ TestSubprg8.lpp fallido"
    COMMAND ${CMAKE_COMMAND} -E echo ""

    COMMAND ${CMAKE_COMMAND} -E echo "Probando TestSubprg9.lpp"
    COMMAND ${PROJECT_BINARY_DIR}/${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/tests/TestSubprg9.lpp 2>/dev/null && ${CMAKE_COMMAND} -E echo "✅ TestSubprg9.lpp pasado" || ${CMAKE_COMMAND} -E echo "❌ TestSubprg9.lpp fallido"
    COMMAND ${CMAKE_COMMAND} -E echo ""

    COMMAND ${CMAKE_COMMAND} -E echo "Probando TestSubprg17.lpp"
    COMMAND ${PROJECT_BINARY_DIR}/${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/tests/TestSubprg17.lpp 2>/dev/null && ${CMAKE_COMMAND} -E echo "✅ TestSubprg17.lpp pasado" || ${CMAKE_COMMAND} -E echo "❌ TestSubprg17.lpp fallido"
    COMMAND ${CMAKE_COMMAND} -E echo ""

    COMMAND ${CMAKE_COMMAND} -E echo "Probando TestSubprg18.lpp"
    COMMAND ${PROJECT_BINARY_DIR}/${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/tests/TestSubprg18.lpp 2>/dev/null && ${CMAKE_COMMAND} -E echo "✅ TestSubprg18.lpp pasado" || ${CMAKE_COMMAND} -E echo "❌ TestSubprg18.lpp fallido"
    COMMAND ${CMAKE_COMMAND} -E echo ""
    DEPENDS ${PROJECT_NAME}
)

add_dependencies(run_tests ${PROJECT_NAME})
