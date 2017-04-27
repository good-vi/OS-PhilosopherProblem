TEMPLATE = subdirs

SUBDIRS += Src

CONFIG(debug, debug|release) {
    SUBDIRS += Tests
}
