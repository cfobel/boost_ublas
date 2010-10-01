#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>
#include "boost/accumulators/accumulators.hpp"
#include "boost/accumulators/statistics/stats.hpp"
#include "boost/accumulators/statistics/mean.hpp"
#include "boost/accumulators/statistics/variance.hpp" 
#include <boost/iterator/counting_iterator.hpp>
#include <boost/range/iterator_range.hpp>
#include <boost/foreach.hpp>
#include <boost/format.hpp>

#define range(x,y) boost::make_iterator_range(_i(x), _i(y))
#define _ boost::format

typedef boost::counting_iterator<int> _i;
using namespace boost::accumulators; 
using namespace boost::numeric::ublas; 
using std::cout;
using std::endl; 

int main () {
    accumulator_set< double, stats< tag::mean, tag::variance > > acc;
    vector<double> v(10);
    scalar_vector<double> w(10, 10);

    BOOST_FOREACH(int i, range(0, v.size())) {
        v[i] = i;
    }

    BOOST_FOREACH(int i, v) { acc(v[i]); }

    cout << v << endl;
    cout << v + w << endl;

    cout << _("%.8f") % mean(acc) << endl;
    cout << _("%.8f") % sqrt(variance(acc)) << endl;

    return 0;
}
