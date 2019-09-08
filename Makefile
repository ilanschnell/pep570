foo.so: foo.c
	python setup.py build_ext --inplace


test: foo.so
	python t.py


clean:
	rm -rf build dist
	rm -f *.o *.so
	rm -f *.pyc
	rm -rf __pycache__
