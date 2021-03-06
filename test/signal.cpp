/**
 * Copyright 2017 Shusheng Shao <iblackangel@163.com>
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <mpl.h>
#include <signal.h>

void sighandler(int signo)
{
	fprintf(stdout, "app exit by signal %s\n", strsignal(signo));
	// exit(0);
}

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "");

	if (signal(SIGINT, sighandler) == SIG_ERR)
		perror("signal SIGINT");
	if (signal(SIGQUIT, sighandler) == SIG_ERR)
		perror("signal SIGQUIT");
	if (signal(SIGTERM, sighandler) == SIG_ERR)
		perror("signal SIGTERM");
    // sigset_t sigset;
	// sigemptyset(&sigset);
	// sigaddset(&sigset, SIGINT);
	// sigaddset(&sigset, SIGTERM);
	// sigaddset(&sigset, SIGQUIT);
	// sigprocmask(SIG_BLOCK, &sigset, 0);
	// for (; ; )
	int res = pause();
	fprintf(stdout, "pause return %d: %s\n", res, strerror(errno));
    return 0;
}
