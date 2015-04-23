#reset and clean up
cd /tmp
rm -rf apr-1.4.6 apr-1.4.6.tar.gz

#get source od APR Util and build
curl -L -O http://archive.apache.org/dist/apr/apr-util-1.4.1.tar.gz

#extract
tar -xzvf apr-util-1.4.1.tar.gz
cd apr-util-1.4.1

#configure, make, make install
./configure --with-apr=/usr/local/apr
#you need that extra parameter to configure because
#apr-util can't really find it because... who knows

make 
sudo make install

#cleanup
cd /tmp
rm -rf apr-util-1.4.1* apr-1.4.6*