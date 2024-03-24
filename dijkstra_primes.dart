import 'dart:io';

class DijkstraPrimes {
  final int last;
  final List<int> _primes = [2];
  final List<int> _pool = [4];

  List<int> get values {
    return _primes;
  }

  DijkstraPrimes(this.last) {
    for (int test = 3; test <= last; ++test) {
      bool isPrim = true;
      for (int index = 0; index < _pool.length - 1; ++index) {
        if (_pool[index] == test) {
          _pool[index] += _primes[index];
          isPrim = false;
        }
      }
      if (isPrim) {
        _primes.add(test);
        _pool.add(test * test);
        // stdout.write('$test ');
      }
    }
  }
}

void main(List<String> arguments) {
  if (arguments.isEmpty) {
    print('pass integer end value to check as prim');
    return;
  }
  int? endValue = int.tryParse(arguments[0]);
  if (endValue == null) {
    print('please pass integer value');
  } else {
    var stopwatch = Stopwatch()..start();
    var prime = DijkstraPrimes(endValue);
    print('calc duration: ${stopwatch.elapsed}\n');

    /*
    for (int value in prime.values) {
      stdout.write('$value ');
    }*/
    stdout.write('\n');
  }
}
