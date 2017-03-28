package testRunnableWithPara;

import java.util.HashMap;
import java.util.concurrent.*;

/**
 * Created by mao on 2016/3/21.
 */
public class testRunnableWithPara {


    public static void main(String args[]){

        ExecutorService e = Executors.newCachedThreadPool();

        Future a = e.submit(new recvTask(Integer.valueOf(11111)));
        boolean b = a.isDone();
        Object aaaa = new HashMap<>();
        try {
            aaaa = a.get(1, TimeUnit.SECONDS);
            int aqwe = 1;
        } catch (InterruptedException e1) {
            e1.printStackTrace();
        } catch (ExecutionException e1) {
            e1.printStackTrace();
        } catch (TimeoutException e1) {
            e1.printStackTrace();
        }

        try {
            aaaa = a.get();
            System.out.println(aaaa);
            Integer qqq = (Integer)aaaa;
        } catch (InterruptedException e1) {
            e1.printStackTrace();
        } catch (ExecutionException e1) {
            e1.printStackTrace();
        }


        e.submit(new recvTask(Integer.valueOf(22222)));
        e.submit(new recvTask(Integer.valueOf(33333)));
        e.submit(new recvTask(Integer.valueOf(44444)));
        e.submit(new recvTask(Integer.valueOf(55555)));
        e.submit(new recvTask(Integer.valueOf(11111)));
        e.submit(new recvTask(Integer.valueOf(22222)));
        e.submit(new recvTask(Integer.valueOf(33333)));
        e.submit(new recvTask(Integer.valueOf(44444)));
        e.submit(new recvTask(Integer.valueOf(55555)));
        e.submit(new recvTask(Integer.valueOf(11111)));
        e.submit(new recvTask(Integer.valueOf(22222)));
        e.submit(new recvTask(Integer.valueOf(33333)));
        e.submit(new recvTask(Integer.valueOf(44444)));
        e.submit(new recvTask(Integer.valueOf(55555)));
        e.submit(new recvTask(Integer.valueOf(11111)));
        e.submit(new recvTask(Integer.valueOf(22222)));
        e.submit(new recvTask(Integer.valueOf(33333)));
        e.submit(new recvTask(Integer.valueOf(44444)));
        e.submit(new recvTask(Integer.valueOf(55555)));
        e.submit(new recvTask(Integer.valueOf(11111)));
        e.submit(new recvTask(Integer.valueOf(22222)));
        e.submit(new recvTask(Integer.valueOf(33333)));
        e.submit(new recvTask(Integer.valueOf(44444)));
        e.submit(new recvTask(Integer.valueOf(55555)));
        e.submit(new recvTask(Integer.valueOf(11111)));
        e.submit(new recvTask(Integer.valueOf(22222)));
        e.submit(new recvTask(Integer.valueOf(33333)));
        e.submit(new recvTask(Integer.valueOf(44444)));
        e.submit(new recvTask(Integer.valueOf(55555)));
        e.submit(new recvTask(Integer.valueOf(11111)));
        e.submit(new recvTask(Integer.valueOf(22222)));
        e.submit(new recvTask(Integer.valueOf(33333)));
        e.submit(new recvTask(Integer.valueOf(44444)));
        e.submit(new recvTask(Integer.valueOf(55555)));
        e.submit(new recvTask(Integer.valueOf(11111)));
        e.submit(new recvTask(Integer.valueOf(22222)));
        e.submit(new recvTask(Integer.valueOf(33333)));
        e.submit(new recvTask(Integer.valueOf(44444)));
        e.submit(new recvTask(Integer.valueOf(55555)));
        e.submit(new recvTask(Integer.valueOf(11111)));
        e.submit(new recvTask(Integer.valueOf(22222)));
        e.submit(new recvTask(Integer.valueOf(33333)));
        e.submit(new recvTask(Integer.valueOf(44444)));
        e.submit(new recvTask(Integer.valueOf(55555)));



        try {
            Thread.sleep(5000);
        } catch (InterruptedException e1) {
            e1.printStackTrace();
        }

        e.submit(new recvTask(Integer.valueOf(11111)));
        e.submit(new recvTask(Integer.valueOf(22222)));
        e.submit(new recvTask(Integer.valueOf(33333)));
        e.submit(new recvTask(Integer.valueOf(44444)));
        e.submit(new recvTask(Integer.valueOf(55555)));

        try {
            Thread.sleep(5000);
        } catch (InterruptedException e1) {
            e1.printStackTrace();
        }
    }


}