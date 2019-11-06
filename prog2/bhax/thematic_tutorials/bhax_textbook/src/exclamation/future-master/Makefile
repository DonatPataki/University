all:	clean fdl cc

fdl:	clean validate_xmllint_future_fdl_hu future_fdl_hu.pdf

cc:	clean validate_xmllint_future_cc_hu future_cc_hu.pdf
	
future_fdl_hu.pdf: future-fdl-hu.xml future-hu.xls
	dblatex future-fdl-hu.xml -p future-hu.xls

future_cc_hu.pdf: future-cc-hu.xml future-hu.xls
	dblatex future-cc-hu.xml -p future-hu.xls
	
.PHONY: validate_jing_future_fdl_hu
validate_jing_future_fdl_hu:
	xmllint --xinclude future-fdl-hu.xml --output output.xml
	java -jar /home/nbatfai/Downloads/jing-trang-20131210/build/jing.jar -c http://docbook.org/xml/5.1/rng/docbookxi.rnc output.xml

.PHONY: validate_jing_future_cc_hu
validate_jing_future_cc_hu:
	xmllint --xinclude future-cc-hu.xml --output output.xml
	java -jar /home/nbatfai/Downloads/jing-trang-20131210/build/jing.jar -c http://docbook.org/xml/5.1/rng/docbookxi.rnc output.xml


.PHONY: validate_xmllint_future_fdl_hu
validate_xmllint_future_fdl_hu:
	xmllint --xinclude future-fdl-hu.xml --output output.xml
	xmllint --relaxng http://docbook.org/xml/5.1/rng/docbookxi.rng output.xml --noout
	rm -f output.xml	

.PHONY: validate_xmllint_future_cc_hu
validate_xmllint_future_cc_hu:
	xmllint --xinclude future-cc-hu.xml --output output.xml
	xmllint --relaxng http://docbook.org/xml/5.1/rng/docbookxi.rng output.xml --noout
	rm -f output.xml	

	
.PHONY: clean
clean:
	rm -vf future-fdl-hu.pdf
	rm -vf future-cc-hu.pdf
